SELECT concat(Name , "(" ,
    SUBSTR(occupation,1,1)
    , ")")
From OCCUPATIONS
Order by Name asc;

SELECT concat("There are a total of ",count(Occupation)," ",lower(Occupation),"s.")
From OCCUPATIONS
Group by Occupation
Order by count(Occupation) asc, Occupation asc;