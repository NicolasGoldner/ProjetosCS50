SELECT name
FROM (directors as d INNER JOIN ratings as r USING(movie_id))
INNER JOIN people ON id = person_id
WHERE r.rating >= 9;
