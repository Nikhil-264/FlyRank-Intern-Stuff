-- SELECT * FROM order_items
-- WHERE order_id = 2
-- ORDER BY quantity * unit_price DESC

-- SELECT * 
-- FROM customers
-- LIMIT 6, 3 -- Here 6 is offset, it skips 6 values in the table and picks next 3

-- Selecting top 3 loyal customers
-- ORDER BY points DESC
-- LIMIT 3

-- Order of clauses is ==> SELECT, FROM, WHERE, ORDER BY, LIMIT

-- In below line the customer_id column is in the both the tables so specify the table name
SELECT order_id, first_name, last_name, orders.customer_id
FROM orders
JOIN customers 
	ON orders.customer_id = customers.customer_id

