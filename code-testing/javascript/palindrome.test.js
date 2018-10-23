const {isPalindrome, reverseString, buildArray, main} = require("./palindrome-product")

test("a number is a palindrome", () => {
  expect(isPalindrome(1001)).toBe(true)
})

test("reverse string reverses a string", () => {
  expect(reverseString("hello")).toBe("olleh")
})

test("buildarray returns an array of products for each number under num and sorts them least to greatest", () => {
  expect(buildArray(5)).toEqual([1, 2, 3, 4, 4, 6, 8, 9, 12, 16])
})

test("main finds the greatest palindrome product", () => {
  expect(main(100)).toEqual(9009)
})
