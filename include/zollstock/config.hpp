#ifndef __ZOLLSTOCK_CONFIG_HPP__
#define __ZOLLSTOCK_CONFIG_HPP__


#ifdef ZOLLSTOCK_USE_MODULES
#  define ZOLLSTOCK_MODULE_EXPORT export
#  define ZOLLSTOCK_CONSTEXPR_VAR inline constexpr
#else
#  define ZOLLSTOCK_MODULE_EXPORT
#  define ZOLLSTOCK_CONSTEXPR_VAR constexpr
#endif


#endif //__ZOLLSTOCK_CONFIG_HPP__
