SELECT BST.N,
    (CASE
        WHEN BST.P IS NULL THEN 'Root'
        WHEN B.PC IS NULL THEN 'Leaf'
        ELSE 'Inner'
    END)
FROM BST
    LEFT JOIN (
        SELECT P, COUNT(P) AS PC
        FROM BST
        GROUP BY P
    ) AS B ON BST.N = B.P
ORDER BY BST.N ASC;