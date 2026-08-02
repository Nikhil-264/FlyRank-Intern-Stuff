SELECT 	
    c.first_name,
    o.order_id,
    sh.name AS shipper
FROM orders o
JOIN customers c
	USING(customer_id)
LEFT JOIN shippers sh
	USING (shipper_id)
