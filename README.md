# Rainbow Attack
Homework of cyber-security (Umons 2023, our teacher PhD R. Absil)
due date : 19/3/2023

## Fast runner:
- [X] generate dataBase : `cd code_file ` after `chmod +x generate`, `./generate`
- [X] create file with password : `cd test`after `chmod +x create-passwd` , `./create-passwd`
- [X] launch attack : `cd code_file` after `chmod +x attack`, `./attack`

## Description
We want to crack a password. We construct a pair dictionary database.

We two phases :
- generate database
- attack

We use the following sql function:
`openSqlite(string name_db)` in attack.cpp

Our code is in `code` folder / filename.cpp 

Some libraries are from :
- PhD R. Absil (https://gitlab.com/rabsil)

(we also took some inspiration from several website as that was granted)

### Manage pre structure
we run /RainbowsAttack/code/generate

We generate the `rainbow_table.db` of `pseudo password` contains `tail | head which is a dictionary `sqlite` database with generate binary.

### launch the attack
we run /RainbowsAttack/code/attack with following attributes :

- /tmp/rainbow_table.db `generated`
- /tmp/password_hash `output for password hash`
- /tmp/out.password `output for passwords`
- `size_password`
- `number_of_reduce`
- /tmp/password_clear `output for passwords in clear

We open database, load_file and the generated hash passwords then we proceed the attack making a walk into pseudo password where the part of generated password match the searched password until the final password.

*Target : In 1h [50, ..., 75]% in function of the generation randomness (> 50%) and we have 100% passwords solved within 3h*

### To submit

- a preprocessing script allowing to **generate** a "sufficiently large" rainbow table RT (not the table itself)

- an **attack** script allowing to exploit RT in order to find passwords from their hashes

- we use `gen-passwd` and `check-passwd` to have our attack script that must allow to input hashes stored in a text file,
  one hash per line, written as a `base-16 string` of `length 64`.

### Remarks

- beginning with size 6 alphanumeric passwords, then increase in [6, ..., 10]
- independent search (multi threading)
- We use a hash table to facilitated hashcode searches 

## Group members

- [X] Alix Declerck (192774)

- [X] Randy Dauchot (190134)

- [X] Guillaume Kerckhofs (191963)

- [X] Clément Samain (200512)

## Project build explanation (on ubuntu 22.04)

1. clone or download github project : https://github.com/Randi-Dcht/cyberSecurity2023/
2. The database `rainbow.db` (build in /tmp folder) sqlite is automatically downloader from `run`

### 1. Generate the database that will be different with each user (< 11h)

run [project]/RainbowAttack/code/generate
`chmod +x run` to make it executable on file system

### 2. Process the attack (< 45min)

run [project]/RainbowAttack/code/attack
`chmod +x run` to make it executable on file system
