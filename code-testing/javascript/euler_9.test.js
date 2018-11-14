const {euler_9} = require("./euler_9")

test("the product of abc such that a^2 + b^2 = c^2 and a + b + c = 1000", () => {
  expect(euler_9()).toBe(31875000)
})
