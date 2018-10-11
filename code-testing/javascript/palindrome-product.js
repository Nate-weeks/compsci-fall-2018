var arr = []
var a;
var b;
for(a=100; a< 1000; a++){
  for(b=a; b<1000; b++){
    let x = a * b
    arr.push(x)
  }
}

function reverseString(str) {
    return str.split("").reverse().join("");
}

isPalindrome = function(num){
  let numString = toString(num)
  let reversedString = reverseString(numstring)
  if(numString==reverseString){
    return true
  } else {
    return false
  }
}

console.log(arr.length)
