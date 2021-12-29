#include <math.h>

#include <gsl/gsl_math.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_sf_airy.h>
#include <gsl/gsl_sf_bessel.h>
#include <gsl/gsl_sf_clausen.h>
#include <gsl/gsl_sf_dawson.h>
#include <gsl/gsl_sf_debye.h>

#include "lauxlib.h"
#include "lua.h"
#include "lualib.h"


static int c_log1p(lua_State *L) {
    double arg = luaL_checknumber(L, 1);
    lua_pushnumber(L, gsl_log1p(arg));
    return 1;
}
static int c_expm1(lua_State *L) {
    double arg = luaL_checknumber(L, 1);
    lua_pushnumber(L, gsl_expm1(arg));
    return 1;
}
static int c_hypot(lua_State *L) {
    double arg1 = luaL_checknumber(L, 1);
    double arg2 = luaL_checknumber(L, 2);    
    lua_pushnumber(L, gsl_hypot(arg1, arg2));
    return 2;
}
static int c_hypot3(lua_State *L) {
    double arg1 = luaL_checknumber(L, 1);
    double arg2 = luaL_checknumber(L, 2);
    double arg3 = luaL_checknumber(L, 2);    
    lua_pushnumber(L, gsl_hypot3(arg1, arg2, arg3));
    return 3;
}
static int c_acosh(lua_State *L) {
    double arg = luaL_checknumber(L, 1);
    lua_pushnumber(L, gsl_acosh(arg));
    return 1;
}
static int c_asinh(lua_State *L) {
    double arg = luaL_checknumber(L, 1);
    lua_pushnumber(L, gsl_asinh(arg));
    return 1;
}
static int c_atanh(lua_State *L) {
    double arg = luaL_checknumber(L, 1);
    lua_pushnumber(L, gsl_atanh(arg));
    return 1;
}
static int c_ldexp(lua_State *L) {
    double arg1 = luaL_checknumber(L, 1);
    double arg2 = luaL_checknumber(L, 2);    
    lua_pushnumber(L, gsl_ldexp(arg1, arg2));
    return 2;
}
static int c_pow_int(lua_State *L) {
    double arg1 = luaL_checknumber(L, 1);
    double arg2 = luaL_checknumber(L, 2);    
    lua_pushnumber(L, gsl_pow_int(arg1, arg2));
    return 2;
}
static int c_pow_2(lua_State *L) {
    double arg = luaL_checknumber(L, 1);
    lua_pushnumber(L, gsl_pow_2(arg));
    return 1;
}
static int c_pow_3(lua_State *L) {
    double arg = luaL_checknumber(L, 1);
    lua_pushnumber(L, gsl_pow_3(arg));
    return 1;
}
static int c_pow_4(lua_State *L) {
    double arg = luaL_checknumber(L, 1);
    lua_pushnumber(L, gsl_pow_4(arg));
    return 1;
}
static int c_pow_5(lua_State *L) {
    double arg = luaL_checknumber(L, 1);
    lua_pushnumber(L, gsl_pow_5(arg));
    return 1;
}
static int c_pow_6(lua_State *L) {
    double arg = luaL_checknumber(L, 1);
    lua_pushnumber(L, gsl_pow_6(arg));
    return 1;
}
static int c_pow_7(lua_State *L) {
    double arg = luaL_checknumber(L, 1);
    lua_pushnumber(L, gsl_pow_7(arg));
    return 1;
}
static int c_pow_8(lua_State *L) {
    double arg = luaL_checknumber(L, 1);
    lua_pushnumber(L, gsl_pow_8(arg));
    return 1;
}
static int c_pow_9(lua_State *L) {
    double arg = luaL_checknumber(L, 1);
    lua_pushnumber(L, gsl_pow_9(arg));
    return 1;
}
static int c_fcmp(lua_State *L) {
    double arg1 = luaL_checknumber(L, 1);
    double arg2 = luaL_checknumber(L, 2);
    double arg3 = luaL_checknumber(L, 2);    
    lua_pushnumber(L, gsl_fcmp(arg1, arg2, arg3));
    return 3;
}
static int c_bessel_j0(lua_State *L) {
    double arg = luaL_checknumber(L, 1);
    lua_pushnumber(L, gsl_sf_bessel_J0(arg));
    return 1;
}
static int c_bessel_j1(lua_State *L) {
    double arg = luaL_checknumber(L, 1);
    lua_pushnumber(L, gsl_sf_bessel_J1(arg));
    return 1;
}
static int c_bessel_jn(lua_State *L) {
    double arg1 = luaL_checknumber(L, 1);
    double arg2 = luaL_checknumber(L, 2);    
    lua_pushnumber(L, gsl_sf_bessel_Jn(arg1, arg2));
    return 2;
}
static int c_bessel_y0(lua_State *L) {
    double arg = luaL_checknumber(L, 1);
    lua_pushnumber(L, gsl_sf_bessel_Y0(arg));
    return 1;
}
static int c_bessel_y1(lua_State *L) {
    double arg = luaL_checknumber(L, 1);
    lua_pushnumber(L, gsl_sf_bessel_Y1(arg));
    return 1;
}
static int c_bessel_yn(lua_State *L) {
    double arg1 = luaL_checknumber(L, 1);
    double arg2 = luaL_checknumber(L, 2);    
    lua_pushnumber(L, gsl_sf_bessel_Yn(arg1, arg2));
    return 2;
}
static int c_bessel_i0(lua_State *L) {
    double arg = luaL_checknumber(L, 1);
    lua_pushnumber(L, gsl_sf_bessel_I0(arg));
    return 1;
}
static int c_bessel_i1(lua_State *L) {
    double arg = luaL_checknumber(L, 1);
    lua_pushnumber(L, gsl_sf_bessel_I1(arg));
    return 1;
}
static int c_bessel_in(lua_State *L) {
    double arg1 = luaL_checknumber(L, 1);
    double arg2 = luaL_checknumber(L, 2);    
    lua_pushnumber(L, gsl_sf_bessel_In(arg1, arg2));
    return 2;
}
static int c_clausen(lua_State *L) {
    double arg = luaL_checknumber(L, 1);
    lua_pushnumber(L, gsl_sf_clausen(arg));
    return 1;
}
static int c_dawson(lua_State *L) {
    double arg = luaL_checknumber(L, 1);
    lua_pushnumber(L, gsl_sf_dawson(arg));
    return 1;
}
static int c_debye_1(lua_State *L) {
    double arg = luaL_checknumber(L, 1);
    lua_pushnumber(L, gsl_sf_debye_1(arg));
    return 1;
}
static int c_debye_2(lua_State *L) {
    double arg = luaL_checknumber(L, 1);
    lua_pushnumber(L, gsl_sf_debye_2(arg));
    return 1;
}
static int c_debye_3(lua_State *L) {
    double arg = luaL_checknumber(L, 1);
    lua_pushnumber(L, gsl_sf_debye_3(arg));
    return 1;
}
static int c_debye_4(lua_State *L) {
    double arg = luaL_checknumber(L, 1);
    lua_pushnumber(L, gsl_sf_debye_4(arg));
    return 1;
}


static int c_rando(lua_State *L) {
    int n = luaL_checknumber(L, 1);
    int seed = luaL_checknumber(L, 2);

    gsl_rng_env_setup();

    gsl_rng* r = gsl_rng_alloc(gsl_rng_mt19937);
    gsl_rng_set(r, seed);

    lua_newtable(L);
    for (int i = 0; i < n; i++) {
        lua_pushnumber(L, i+1);
        lua_pushnumber(L, gsl_rng_uniform(r));
        lua_rawset(L, -3);     
    }

    gsl_rng_free(r);

    return 1;
}




// library to be registered
static const struct luaL_Reg lua_gsl[] = {
    {"log1p", c_log1p},
    {"expm1", c_expm1},
    {"hypot", c_hypot},
    {"hypot3", c_hypot3},
    {"acosh", c_acosh},
    {"asinh", c_asinh},
    {"atanh", c_atanh},
    {"ldexp", c_ldexp},
    {"pow_int", c_pow_int},
    {"pow_2", c_pow_2},
    {"pow_3", c_pow_3},
    {"pow_4", c_pow_4},
    {"pow_5", c_pow_5},
    {"pow_6", c_pow_6},
    {"pow_7", c_pow_7},
    {"pow_8", c_pow_8},
    {"pow_9", c_pow_9},
    {"fcmp", c_fcmp},
    {"bessel_j0", c_bessel_j0},
    {"bessel_j1", c_bessel_j1},
    {"bessel_jn", c_bessel_jn},
    {"bessel_y0", c_bessel_y0},
    {"bessel_y1", c_bessel_y1},
    {"bessel_yn", c_bessel_yn},
    {"bessel_i0", c_bessel_i0},
    {"bessel_i1", c_bessel_i1},
    {"bessel_in", c_bessel_in},
    {"clausen", c_clausen},
    {"dawson", c_dawson},
    {"debye_1", c_debye_1},
    {"debye_2", c_debye_2},
    {"debye_3", c_debye_3},
    {"debye_4", c_debye_4},
    {"rando", c_rando},
    {NULL, NULL}       /* sentinel */
};

// name of this function is not flexible
int luaopen_lua_gsl(lua_State *L) {
    luaL_newlib(L, lua_gsl);
    return 1;
}
