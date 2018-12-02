const {euler_12} = require("./euler_12")

test("checks for triangle number with a given number of factors", () => {
  expect(euler_12(5)).toBe(28)
})
