/** Program by Nate Weeks to solve euler 4
October 2018
**/


function buildArray(num) {
  var arr = []
  var a;
  var b;
  for(a=1; a < num; a++){
    for(b=a; b<num; b++){
      let x = a * b
      arr.push(x)
    }
  }
  return arr.sort((a, b) => a - b);
}

function reverseString(str) {
    return str.split("").reverse().join("");
}

isPalindrome = function(num){
  let numString = String(num)
  let reversedString = reverseString(numString)
  if(numString==reversedString){
    return true
  } else {
    return false
  }
}

function main(num) {
  let answer = 0;
  arr = buildArray(num)
  for(i=arr.length - 1; i>0; i--){
    if (isPalindrome(arr[i]) == true){
      answer = arr[i]
      break
    }
  }
  return answer
}

console.log(main(1000))

module.exports = {isPalindrome, reverseString, buildArray, main};
