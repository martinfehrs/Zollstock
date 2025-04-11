#ifndef __ZOLLSTOCK_TESTS_FEATURES_HPP__
#define __ZOLLSTOCK_TESTS_FEATURES_HPP__


#include <algorithm>
#include <ranges>
#include <filesystem>
#include <set>
#include <vector>
#include <string>
#include <utility>


using feature_set = std::set<std::string>;
using feature_dependencies = std::vector<std::pair<std::string, std::string>>;


[[nodiscard]] inline std::ranges::forward_range auto split_feature(const std::string& feature)
{
    static const auto to_string = [](auto&& rng)
    {
        return std::string{ std::ranges::begin(rng), std::ranges::end(rng) };
    };

    return std::ranges::views::split(feature, '.') | std::ranges::views::transform(to_string);
}

[[nodiscard]] inline bool is_sub_feature(const std::string& feature, const std::string& sub_feature)
{
    auto feature_sequence     = split_feature(feature   );
    auto sub_feature_sequence = split_feature(sub_feature);

    auto[it1, it2] = std::ranges::mismatch(feature_sequence, sub_feature_sequence);

    return it1 == std::ranges::end(feature_sequence)
        && it2 != std::ranges::end(sub_feature_sequence);
}

[[nodiscard]] inline feature_dependencies remove_group_deps(
    const feature_dependencies& unfiltered_deps
)
{
    const auto if_group_feature = [&unfiltered_deps](const auto& entry)
    {
        auto it = std::ranges::find(
            unfiltered_deps, entry.second, &feature_dependencies::value_type::first
        );

        return it != std::ranges::end(unfiltered_deps);
    };

    auto group_feature_deps = unfiltered_deps | std::ranges::views::filter(if_group_feature);

    feature_dependencies filtered_deps;

    std::ranges::set_difference(
        unfiltered_deps,
        group_feature_deps,
        std::back_inserter(filtered_deps)
    );

    return filtered_deps;
}

[[nodiscard]] inline bool valid_feature_deps(
    const feature_set& features, const feature_dependencies& deps
)
{
    return std::ranges::all_of(
        deps,
        [&features](const auto& entry)
        {
            return features.contains(entry.first) && features.contains(entry.second);
        }
    );
}

[[nodiscard]] inline feature_dependencies gen_feature_deps(
    const feature_set& features, const feature_dependencies& additional_deps
)
{
    feature_dependencies unfiltered_deps;

    for(const auto& feature_1 : features)
    {
        for(const auto& feature_2 : features)
        {
            if (is_sub_feature(feature_1, feature_2))
                unfiltered_deps.emplace_back(feature_1, feature_2);
        }
    }

    unfiltered_deps.insert(
        std::ranges::end(unfiltered_deps),
        std::ranges::begin(additional_deps),
        std::ranges::end(additional_deps)
    );

    auto filtered_deps = remove_group_deps(unfiltered_deps);

    std::ranges::sort(filtered_deps);

    return filtered_deps;
}


#endif //__ZOLLSTOCK_TESTS_FEATURES_HPP__
