SELECT title, rating
FROM (SELECT * FROM movies INNER JOIN ratings WHERE id = movie_id)
WHERE year = 2010
    AND rating NOT NULL
ORDER BY rating DESC, title;
