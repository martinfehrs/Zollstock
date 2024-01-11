#include <catch2/catch_all.hpp>
#include <zollstock/angle_unit_constants.hpp>
#include <zollstock/unit_algorithms.hpp>


using namespace zollstock;


TEST_CASE("angle-unit-constants", "[angle][unit][constants]")
{

    REQUIRE(prad           == picoradian    {});
    REQUIRE(micrad         == microradian   {});
    REQUIRE(mrad           == milliradian   {});
    REQUIRE(crad           == centiradian   {});
    REQUIRE(rad            == radian        {});
    REQUIRE(darad          == decaradian    {});
    REQUIRE(hrad           == hectoradian   {});
    REQUIRE(krad           == kiloradian    {});
    REQUIRE(Mrad           == megaradian    {});
    REQUIRE(Grad           == gigaradian    {});
    REQUIRE(Trad           == teraradian    {});
    REQUIRE(Prad           == petaradian    {});
    REQUIRE(Erad           == exaradian     {});
    REQUIRE(Zrad           == zettaradian   {});
    REQUIRE(Yrad           == yottaradian   {});
    REQUIRE(Rrad           == ronnaradian   {});
    REQUIRE(Qrad           == quettaradian  {});

    REQUIRE(deg            == degree        {});

    REQUIRE(qas           == quektoarcsecond {});
    REQUIRE(ras           == rontoarcsecond  {});
    REQUIRE(yas           == yoktoarcsecond  {});
    REQUIRE(zas           == zeptoarcsecond  {});
    REQUIRE(aas           == attoarcsecond   {});
    REQUIRE(fas           == femtoarcsecond  {});
    REQUIRE(pas           == picoarcsecond   {});
    REQUIRE(nas           == nanoarcsecond   {});
    REQUIRE(micas         == microarcsecond  {});
    REQUIRE(mas           == milliarcsecond  {});
    REQUIRE(cas           == centiarcsecond  {});
    REQUIRE(das           == deciarcsecond   {});
    REQUIRE(arcsec        == arcsecond       {});
    REQUIRE(daas          == decaarcsecond   {});
    REQUIRE(has           == hectoarcsecond  {});
    REQUIRE(kas           == kiloarcsecond   {});
    REQUIRE(Mas           == megaarcsecond   {});
    REQUIRE(Gas           == gigaarcsecond   {});
    REQUIRE(Tas           == teraarcsecond   {});
    REQUIRE(Pas           == petaarcsecond   {});
    REQUIRE(Eas           == exaarcsecond    {});
    REQUIRE(Zas           == zettaarcsecond  {});
    REQUIRE(Yas           == yottaarcsecond  {});
    REQUIRE(Ras           == ronnaarcsecond  {});
    REQUIRE(Qas           == quettaarcsecond {});

    REQUIRE(qgon           == quektogradian {});
    REQUIRE(rgon           == rontogradian  {});
    REQUIRE(ygon           == yoktogradian  {});
    REQUIRE(zgon           == zeptogradian  {});
    REQUIRE(agon           == attogradian   {});
    REQUIRE(fgon           == femtogradian  {});
    REQUIRE(pgon           == picogradian   {});
    REQUIRE(ngon           == nanogradian   {});
    REQUIRE(micgon         == microgradian  {});
    REQUIRE(mgon           == milligradian  {});
    REQUIRE(cgon           == centigradian  {});
    REQUIRE(dgon           == decigradian   {});
    REQUIRE(gon            == gradian       {});
    REQUIRE(dagon          == decagradian   {});
    REQUIRE(hgon           == hectogradian  {});
    REQUIRE(kgon           == kilogradian   {});
    REQUIRE(Mgon           == megagradian   {});
    REQUIRE(Ggon           == gigagradian   {});
    REQUIRE(Tgon           == teragradian   {});
    REQUIRE(Pgon           == petagradian   {});
    REQUIRE(Egon           == exagradian    {});
    REQUIRE(Zgon           == zettagradian  {});
    REQUIRE(Ygon           == yottagradian  {});
    REQUIRE(Rgon           == ronnagradian  {});
    REQUIRE(Qgon           == quettagradian {});

}
