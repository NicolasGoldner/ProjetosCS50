SELECT COUNT(title)
FROM movies
INNER JOIN ratings
WHERE movie_id = id
    AND rating = 10;
