gsl = require "lua_gsl"

print("gsl.bessel(5): " .. gsl.bessel(5))
print("gsl.mysin(93): " .. gsl.mysin(93))

print("gsl.rando(5, 123)")
local rnd = gsl.rando(5, 123)
for i, v in ipairs(rnd) do
	print(i,v)
end