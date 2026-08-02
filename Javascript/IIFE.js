// Immediately Invoked Function Expression(IIFE)

// to run function immediately after declaration
(function chai(){
        console.log(`welcome`);
})();

const p = (function add(a, b){
        return a + b;
})(3, 7);

console.log(p);

// as arrow function
( () => {
        console.log(`welcome`);
})();

// global execution context
  // function execution context
  // function execution context
  // execution phase
  // how the code is executed:
  //Code: 
        //   let val1 = 10
        //   let val2 = 20
        //   function add(val1, val2){
        //           return val1 + val2
        //   }
        //   let result1 = add(val1, val2)
        //   let result2 = add(30, 40)

  // 1. Global Execution --> this
  // 2. Memory phase / memory creation
        // val1 = undefined
        // val2 = undefined
        // add --> definition
        // result1 = undefined
        // result2 = undefined
  // 3.  Execution phase
        // val1 = 10
        // val2 = 20
        // add --> new environment + execution thread is made for each function call
                        //  |
                        //  |
                        //  V // this is done recursively
                        // 1. Memory phase
                                // val1 = undefined
                                // val2 = undefined
                                //total = undefined
                        // execution phase 
                                // val1 = 10
                                // val2 = 20
                                // total = 30
                        // this executional context made for function is deleted after use
        
