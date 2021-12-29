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


% for f in funcs:
% if f.nargs == 1:
static int c_${f.name}(lua_State *L) {
    double arg = luaL_checknumber(L, 1);
    lua_pushnumber(L, gsl_${f.fullname}(arg));
    return 1;
}
% endif
% if f.nargs == 2:
static int c_${f.name}(lua_State *L) {
    double arg1 = luaL_checknumber(L, 1);
    double arg2 = luaL_checknumber(L, 2);    
    lua_pushnumber(L, gsl_${f.fullname}(arg1, arg2));
    return 2;
}
% endif
% if f.nargs == 3:
static int c_${f.name}(lua_State *L) {
    double arg1 = luaL_checknumber(L, 1);
    double arg2 = luaL_checknumber(L, 2);
    double arg3 = luaL_checknumber(L, 2);    
    lua_pushnumber(L, gsl_${f.fullname}(arg1, arg2, arg3));
    return 3;
}
% endif
% endfor


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
    % for f in funcs:
    {"${f.name}", c_${f.name}},
    % endfor
    {"rando", c_rando},
    {NULL, NULL}       /* sentinel */
};

// name of this function is not flexible
int luaopen_lua_gsl(lua_State *L) {
    luaL_newlib(L, lua_gsl);
    return 1;
}
