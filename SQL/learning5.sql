-- ALTER TABLE person
-- ALTER COLUMN name
-- SET DATA TYPE VARCHAR(150);
-- SELECT * FROM person;
-- u didnt set the default value while making the table 
-- u can add do that using alter

-- ALTER TABLE person
-- ALTER COLUMN name
-- SET DEFAULT 'unknown';

-- CHECK constraint

-- ALTER TABLE person
-- ADD COLUMN 
-- 	mob VARCHAR(15)
-- 		CHECK (LENGTH(mob) >= 10);
		
-- INSERT INTO person(mob)
-- VALUES (123456789); -- will give error as the number is of length < 10

-- ALTER TABLE person
-- DROP CONSTRAINT person_mob_check;

-- INSERT TABLE person

-- NAMED CONTRAINTS

-- CREATE TABLE customers(
-- 	cust_id SERIAL PRIMARY KEY,
-- 	cust_name VARCHAR(100) NOT NULL
-- );

-- CREATE TABLE orders(
-- 	ord_id SERIAL PRIMARY KEY,
-- 	ord_data DATE NOT NULL,
-- 	price NUMERIC NOT NULL,
-- 	cust_id IN
-- )

SELECT * FROM orders;
