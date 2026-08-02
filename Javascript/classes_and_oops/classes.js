// // class user{
// //         constructor(username, email, password){
// //                 this.username = username;
// //                 this.email = email;
// //                 this.password = password;
// //         }
// //         encrytPassword(){
// //                 //encrypt the password
// //                 return `${this.password}abs`;
// //         }

// //         changeUserName(){
// //                 return `${this.username.toUpperCase()}`;
// //         }
        
// // }
// // const chai = new user("chai", "chai@bo.com", "123");

// // console.log(chai.encrytPassword());
// // console.log(chai.changeUserName());


// // function User(username, email, password){
// //         this.username = username;
// //         this.email = email;
// //         this.password = password;
// // }

// // User.prototype.encrytPassword = function(){
// //         //encrypt the password
// //         return `${this.password}abs`;
// // }
// // // inheritance

// class User{
//         constructor(username){
//                 this.username = username;
//         }

//         logMe(){
//                 console.log(`Hello ${this.username}`);
//         }
// }

// class Teacher extends User{
//         constructor(username, subject){
//                 super(username);
//                 this.subject = subject;
//         }
//         logSubject(){
//                 console.log(`your subject is ${this.subject}`);
//         }
// }
// const chai = new Teacher("chai", "maths");

// chai.logSubject(); // inherited from Teacher 
// chai.logMe();

// const masalaChai = new User("masalaChai");
// masalaChai.logMe();
// // masalaChai.logSubject(); // error: The method logSubject() is not defined on the User class, only on the Teacher class.

// console.log(chai instanceof Teacher); // true
// console.log(chai instanceof User); // true

// console.log(masalaChai instanceof Teacher); // false
// console.log(masalaChai instanceof User); // true

