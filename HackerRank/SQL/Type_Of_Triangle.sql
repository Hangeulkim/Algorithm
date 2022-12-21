Select 
    CASE WHEN a = b and b = c then "Equilateral"
        WHEN a + b <= c or b + c <= a or c + a <= b then "Not A Triangle"
        WHEN a != b and b != c and c != a then "Scalene"
        ELSE "Isosceles"
    END
from TRIANGLES;