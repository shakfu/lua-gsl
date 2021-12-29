gsl = require "lua_gsl"

print("gsl.bessel_j0(5): " .. gsl.bessel_j0(5))
print("gsl.asinh(93): " .. gsl.asinh(93))

print("gsl.rando(5, 123)")
local rnd = gsl.rando(5, 123)
for i, v in ipairs(rnd) do
	print(i,v)
end