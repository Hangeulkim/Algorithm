SELECT 
    MAX(CASE WHEN occ.OCCUPATION = 'Doctor' THEN occ.NAME END) AS 'Doctor',
    MAX(CASE WHEN occ.OCCUPATION = 'Professor' THEN occ.NAME END) AS 'Professor',
    MAX(CASE WHEN occ.OCCUPATION = 'Singer' THEN occ.NAME END) AS 'Singer',
    MAX(CASE WHEN occ.OCCUPATION = 'Actor' THEN occ.NAME END) AS 'Actor'
FROM(
        SELECT Name, Occupation, 
            row_number() over (partition by Occupation Order by Name) as rn
        FROM Occupations
    ) as occ
GROUP BY occ.rn
ORDER BY occ.rn;