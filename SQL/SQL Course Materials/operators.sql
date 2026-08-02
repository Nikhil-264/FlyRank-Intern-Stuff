SELECT * 
FROM customers
-- WHERE birth_date >= '1990-01-01' AND points < 1000

-- U can use operators like >, <, <=, >=, =, !=, <> -- last two are not equal to operators
-- order of logical operators ==>  AND > OR
-- WHERE state NOT IN ('VA', 'FL', 'GA')
-- IN for taking in praenthese, NOT IN gieves values outside the parentheses

-- INstead of uaing like points >= 1000 and points <= 3000 we can use between operator
-- WHERE points BETWEEN 1000 AND 3000

-- can use like operator as follows -- last name starts with b is written as
-- WHERE last_name LIKE '%b%' -- Denotes b is somewhere in this name	
-- U can use '_y' like for second character is y for the word

-- for searching string use REGEXP
-- WHERE last_name REGEXP 'field' -- for anywhere -- '^field' (starting with field), 'field$' - (word must end with field)
-- for searching multiple words exp searching field and mac use 'field|mac'
-- ^ beginning
-- $ end
-- | logival or
-- [abcd]
-- [a-f]
ORDER BY first_name DESC
--  will sort the table based on the first_name

-- We can add more parameter like ORDER BY first_name, state it will sort it based on the both bath on the priority
-- If we do like below
-- SELECT first_name, last-name
-- FROM customers
-- ORDER BY 1, 2 -- This will sort that 1 is first_name and 2 id last_name its same order as select line
-- Avoid this in general use column names