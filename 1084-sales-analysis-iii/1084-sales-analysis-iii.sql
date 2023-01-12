# Write your MySQL query statement below

select distinct S.product_id, P.product_name from Product P left join Sales S on P.product_id=S.product_id
where S.product_id not in(select product_id from Sales where sale_date > '2019-03-31'
OR sale_date < '2019-01-01');