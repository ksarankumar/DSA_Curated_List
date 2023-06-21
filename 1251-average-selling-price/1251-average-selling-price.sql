/* Write your T-SQL query statement below */

SELECT 
P.product_id AS product_id ,
ROUND(SUM(S.units * P.price * 1.0) / SUM(S.units),2) AS average_price  -- * 1.0 to make it decimal ,otherwise wont come in decimal
FROM Prices P
LEFT JOIN UnitsSold S
ON P.product_id  = S.product_id 
AND S.purchase_date BETWEEN P.start_date AND P.end_date   
GROUP BY P.product_id
