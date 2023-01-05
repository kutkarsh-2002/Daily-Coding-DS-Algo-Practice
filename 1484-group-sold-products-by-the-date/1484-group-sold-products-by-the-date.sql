# Write your MySQL query statement below

select sell_date, count(sell_date) as num_sold, Group_concat(distinct product order by product) as products
from 
(select distinct sell_date, product from Activities) as Activities group by sell_date;
