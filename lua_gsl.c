#include <math.h>

#include <gsl/gsl_rng.h>
#include <gsl/gsl_sf_bessel.h>

#include "lauxlib.h"
#include "lua.h"
#include "lualib.h"

static int my_sin(lua_State *L) {
    double arg = luaL_checknumber(L, 1);
    lua_pushnumber(L, sin(arg));
    return 1;
}


static int c_bessel(lua_State *L) {
    // check and fetch the arguments
    double arg = luaL_checknumber(L, 1);

    // push the results
    lua_pushnumber(L, gsl_sf_bessel_J0(arg));

    // return number of results
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
    {"bessel", c_bessel},
    {"rando", c_rando},
    {"mysin", my_sin}, /* names can be different */
    {NULL, NULL}       /* sentinel */
};

// name of this function is not flexible
int luaopen_lua_gsl(lua_State *L) {
    luaL_newlib(L, lua_gsl);
    return 1;
}
