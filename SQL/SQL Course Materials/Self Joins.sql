-- USE sql_hr;

-- SELECT 
-- 	e.employee_id,
-- 	e.first_name,
--     m.first_name AS Manager
-- FROM employees e
-- JOIN employees m
-- 	ON e.reports_to = m.employee_id

-- Joining Multiple Tables

USE sql_store;
SELECT 
	o.order_id,
    o.order_date,
    c.first_name,
    c.last_name,
    os.name AS Status
FROM orders o
JOIN customers c
	ON o.customer_id = c.customer_id
JOIN order_statuses os
	ON o.status = os.order_status_id

