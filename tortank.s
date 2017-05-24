.name "Tortank"
.comment "Can't touch this"

start:	
sti r1, %:live, %1

ld %-350, r2
ld %0, r3
ld %4, r4
ld %1, r5
ld %0, r16
ld %656, r10

live:
live %1

fork:
fork %:live
	
sti r1, %:live2, %1

while1:	
sti r16, %0, r2

live2:
live %1

add r2, r4, r2
add r3, r5, r3
and r3, %64, r15
zjmp %:while1

sti r5, %:start, %-4
sti r1, %:start, %-5
sti r10, %:start, %-9

	
sti r1, %:live3, %1

ld %150, r2
ld %0, r3
	
while2:	
sti r16, %0, r2

live3:
live %1

add r2, r4, r2
add r3, r5, r3
and r3, %32, r15
zjmp %:while2


sti r1, %:live4, %1
sti r1, %:live5, %1
	
live4:
live %1

fork %:shield
	
xor %0, %0, r16
zjmp %:start

shield:

ld %-150, r2
ld %0, r3
ld %4, r4
ld %1, r5
ld %0, r16

live5:
live %1

add r2, r4, r2
add r3, r5, r3
and r3, %64, r15
zjmp %:live5

xor %0, %0, r16
zjmp %:shield