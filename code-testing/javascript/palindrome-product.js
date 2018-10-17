function buildArray() {
  var arr = []
  var a;
  var b;
  for(a=100; a< 1000; a++){
    for(b=a; b<1000; b++){
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

function main() {
  arr = buildArray()
  for(i=arr.length - 1; i>0; i--){
    if (isPalindrome(arr[i]) == true){
      return arr[i]
      break
    }
  }
}

console.log(main())
