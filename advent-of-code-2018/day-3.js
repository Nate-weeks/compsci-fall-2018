// code by nate weeks to solve AOC2018 day 3
// December 2018

function create_array(num){
  let array = new Array(num);

  for (var i = 0; i < array.length; i++) {
    array[i] = new Array(num);
  }

  for(i=0;i<array.length;i++){
    for(j=0;j<array.length;j++){
      array[i][j] = 0;
    }
  }
  return array;
}

// iterates through array starting at the starting point then populates it
// with ones according to box size - changes to 2's if the number is already a 1
function populate_array(array, id, start_x, start_y, box_x, box_y){
  let box_stop_x = box_x + start_x;
  let box_stop_y = box_y + start_y;
  for(y=start_y; y<box_stop_y; y++){
    for(x=start_x; x<box_stop_x; x++){
      if(array[x][y] == 0){
        array[x][y] = id
      } else {
        array[x][y] = 'X'
      }
    }
  }
  return array;
}

function check_array(array, id, start_x, start_y, box_x, box_y){
  let answer = id
  let box_stop_x = box_x + start_x;
  let box_stop_y = box_y + start_y;
  for(y=start_y; y<box_stop_y; y++){
    for(x=start_x; x<box_stop_x; x++){
      if(array[x][y] == 'X'){
        answer = 'false';
      }
    }
  }
  return answer;
}

function part_one(input){

  let array = create_array(1000)
  let answer = 0;

  // format array into an array of nested arrays so that the starting coordinate
  // is in one array and the box size in in the next array
  let formatted_input =
  input.map(function(string){
    return string.split(' ');
  })
  .map(function(substring){
    return [substring[2].replace(':', '').split(','), substring[3].split('x'), substring[0].replace('#', '')]
  })
  formatted_input.forEach(function(line){
    let x = parseInt(line[0][0])
    let y = parseInt(line[0][1])
    let box_x = parseInt(line[1][0])
    let box_y = parseInt(line[1][1])
    let id = parseInt(line[2])
    populate_array(array, id, x, y, box_x, box_y)
  })
  for(i=0;i<array.length;i++){
    for(j=0;j<array.length;j++){
      if(array[i][j] == 'X'){
        answer += 1;
      }
    }
  }
  console.log(array)
  return answer
}

function part_two(input){
  let array = create_array(1000)
  let answer = 0;

  // format array into an array of nested arrays so that the starting coordinate
  // is in one array and the box size in in the next array
  let formatted_input =
  input.map(function(string){
    return string.split(' ');
  })
  .map(function(substring){
    return [substring[2].replace(':', '').split(','), substring[3].split('x'), substring[0].replace('#', '')]
  })
  formatted_input.forEach(function(line){
    let x = parseInt(line[0][0])
    let y = parseInt(line[0][1])
    let box_x = parseInt(line[1][0])
    let box_y = parseInt(line[1][1])
    let id = parseInt(line[2])
    populate_array(array, id, x, y, box_x, box_y)
    check_array(array, id, x, y, box_x, box_y)
  })
  formatted_input.some(function(line){
    let x = parseInt(line[0][0])
    let y = parseInt(line[0][1])
    let box_x = parseInt(line[1][0])
    let box_y = parseInt(line[1][1])
    let id = parseInt(line[2])
    answer = check_array(array, id, x, y, box_x, box_y)
    return answer === id;
    })
  return answer
}

module.exports = {part_one, part_two}
