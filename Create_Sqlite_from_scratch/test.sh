#!/bin/bash
cd build && cmake .. && make 
./sqlite_scratch << 'EOF'
insert
select
.exit
EOF