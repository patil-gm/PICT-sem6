const res = document.getElementById("result");
const toast = document.getElementById("toast");

function calculate(value) 
{
  const calculatedValue = eval(value || null);
  console.log(calculatedValue);
  if (calculatedValue=='Infinity') {
    res.value = " ";
    alert("Can't divide with 0");  
  } 
  else {
    res.value = calculatedValue;
  }
}

function liveScreen(enteredValue) {
  if (!res.value) {
    res.value = "";
  }
  res.value += enteredValue;
}


document.addEventListener("keydown", keyboardInputHandler);


function keyboardInputHandler(e) {
  
  e.preventDefault();
  

  //numbers
  if (e.key === "0") {
    res.value += "0";
  } else if (e.key === "1") {
    res.value += "1";
  } else if (e.key === "2") {
    res.value += "2";
  } else if (e.key === "3") {
    res.value += "3";
  } else if (e.key === "4") {
    res.value += "4";
  } else if (e.key === "5") {
    res.value += "5";
  } else if (e.key === "6") {
    res.value += "6";
  } else if (e.key === "7") {
    res.value += "7";
  } else if (e.key === "7") {
    res.value += "7";
  } else if (e.key === "8") {
    res.value += "8";
  } else if (e.key === "9") {
    res.value += "9";
  }
  

  //operators
  if (e.key === "+") {
    res.value += "+";
  } else if (e.key === "-") {
    res.value += "-";
  } else if (e.key === "*") {
    res.value += "*";
  } else if (e.key === "/") {
    res.value += "/";
  }

  if (e.key === ".") {
    res.value += ".";
  }

  
  if (e.key === "Enter") {
    calculate(result.value);
  }
}
