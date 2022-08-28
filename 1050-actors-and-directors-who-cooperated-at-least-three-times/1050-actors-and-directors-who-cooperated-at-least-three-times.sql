# Write your MySQL query statement below

select actor_id, director_id from ActorDirector 
GROUP BY actor_id,director_id HAVING COUNT(director_id) >= 3
