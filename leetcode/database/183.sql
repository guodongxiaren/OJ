# 子查询 
# 方案1：NOT IN（779ms）
select Name 
from Customers
where Id not in (
    select CustomerId 
    from Orders
    );

# 方案1：<> ALL（692ms）
select Name 
from Customers
where Id <> all (
    select CustomerId 
    from Orders
    );
