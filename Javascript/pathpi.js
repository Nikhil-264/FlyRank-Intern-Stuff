const discripter = Object.getOwnPropertyDescriptor(Math, "PI")

console.log(discripter);

const chai = {
        name : 'ginger tea',
        price : 250,
}

console.log(Object.getOwnPropertyDescriptor(chai, "name"));

Object.defineProperty(chai, 'name', {
        writable: false,
        enumerable : false,
        configurable: true,
})
console.log(Object.getOwnPropertyDescriptor(chai, "name"));