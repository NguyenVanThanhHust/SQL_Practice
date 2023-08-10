#!/bin/bash
cd build && cmake .. && make 
./sqlite_scratch << 'EOF'
insert 1 test test@gmail.com
select
.exit
EOF