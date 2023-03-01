function myFunction() {
  let fname = document.getElementById("fname").value;
  let lname = document.getElementById("lname").value;
  let phone = document.getElementById("phone").value;
  let mail = document.getElementById("mail").value;
//   let dob = document.getElementById("dob").value;
  let p1 = document.getElementById("p1").value;
  let p2 = document.getElementById("p2").value;
 
  console.log(fname);
  console.log(lname);
  console.log(mail);
//   console.log(dob);
  console.log(p1);
  console.log(p2);

  if (fname == "") {
    alert("First Name must be filled out");
    return false;
  }
  if (lname == "") {
    alert("Last Name must be filled out");
    return false;
  }
  if(phone.length!=10){
    alert("Contact No Should contain 10 numbers..!");
    return false;
  }

  for(let i=0;i<10;i++){
    if(phone[i]>'9' || phone[i]<'0'){
        alert("Contact No Should contain only numbers..!");
        return false;
    }
  }

  var validRegex = /^[a-zA-Z0-9.!#$%&'*+/=?^_`{|}~-]+@[a-zA-Z0-9-]+(?:\.[a-zA-Z0-9-]+)*$/;

  if (!mail.match(validRegex)) {
    alert("Invalid email address!");
    return false;
  }

  if(p1!=p2){
     alert("your passwords are not matching ..!");
    return false;
  }

  
}

   