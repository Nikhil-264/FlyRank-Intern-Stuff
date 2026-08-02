// // const tinderUser = new Object(); //  singletone object
// const tinderUser = {} // Non singletone object

// // tinderUser.name = "John";
// // tinderUser.age = 30;
// // tinderUser.location = "USA";
// // tinderUser.email = "nikhil@gOne.cum"
// // tinderUser.isLoggedIn = false;

// // console.log(tinderUser);

// const regularUser = {
//         email: "blahblahblah.com",
//         fullname:{
//                 userFullName :{
//                         firstName: "John",
//                         lastName: "Doe",
//                 },
//                 age: 30,
//         }
// }// these are nested objects

// console.log(regularUser.fullname);

const obj1 = {1: "A", 2 : "B"};
const obj2 = {4: "A", 3 : "B"};

const obj3 = Object.assign(obj1, obj2); // this will merge the two objects
// console.log(obj3); // this will merge the two objects and assign them to obj1
// // we can also give empty array in the biginning of the object.assign to make a new object

// const obj3 = {...obj1, ...obj2}; // this is the new way to merge the objects
// console.log(obj1); // this operation will not assign to obj1

// Array of objects
const users = [
        {
                id: 1,
                email : "blahblah.com",
                Hobby : "Football",
        },
        {
                id: 2,
                email : "blahblah@.com",
                Hobby : "Cricket",
        },
        {
                id: 3,
                email : "blahblah@.com",
                Hobby : "Hockey",
        }
]

//accessing elements
console.log(users[1].email)


const course = {
        courseName: "JS Learn",
        price : 200,
        courseInstrutor : "Nikhil",
}

// course.courseInstrutor

const {courseInstrutor : instructor} = course;

console.log(instructor); //  destructuring the object

// const navbar = ({company}) => {
//         console.log("Navbar is loading"); // destructuring in react
// }

// navbar(company = "hitesh")

//JSON
// {
//         "name": "Nikhil",
//         "age": 20,
//         "location": "India",
// }// JSON needs key value both as strings

// {
//         "results": [
//           {
//             "gender": "female",
//             "name": {
//               "title": "Miss",
//               "first": "Jennie",
//               "last": "Nichols"
//             },
//             "location": {
//               "street": {
//                 "number": 8929,
//                 "name": "Valwood Pkwy",
//               },
//               "city": "Billings",
//               "state": "Michigan",
//               "country": "United States",
//               "postcode": "63104",
//               "coordinates": {
//                 "latitude": "-69.8246",
//                 "longitude": "134.8719"
//               },
//               "timezone": {
//                 "offset": "+9:30",
//                 "description": "Adelaide, Darwin"
//               }
//             },
//             "email": "jennie.nichols@example.com",
//             "login": {
//               "uuid": "7a0eed16-9430-4d68-901f-c0d4c1c3bf00",
//               "username": "yellowpeacock117",
//               "password": "addison",
//               "salt": "sld1yGtd",
//               "md5": "ab54ac4c0be9480ae8fa5e9e2a5196a3",
//               "sha1": "edcf2ce613cbdea349133c52dc2f3b83168dc51b",
//               "sha256": "48df5229235ada28389b91e60a935e4f9b73eb4bdb855ef9258a1751f10bdc5d"
//             },
//             "dob": {
//               "date": "1992-03-08T15:13:16.688Z",
//               "age": 30
//             },
//             "registered": {
//               "date": "2007-07-09T05:51:59.390Z",
//               "age": 14
//             },
//             "phone": "(272) 790-0888",
//             "cell": "(489) 330-2385",
//             "id": {
//               "name": "SSN",
//               "value": "405-88-3636"
//             },
//             "picture": {
//               "large": "https://randomuser.me/api/portraits/men/75.jpg",
//               "medium": "https://randomuser.me/api/portraits/med/men/75.jpg",
//               "thumbnail": "https://randomuser.me/api/portraits/thumb/men/75.jpg"
//             },
//             "nat": "US"
//           }
//         ],
//         "info": {
//           "seed": "56d27f4a53bd5441",
//           "results": 1,
//           "page": 1,
//           "version": "1.4"
//         }
//       }

