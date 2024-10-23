## REGEX

*(Voir les REGEX dans le diapo du cours 2)*

1) Interpreting regular expressions
	- `.` : N'importe quelle caractère
	- `\.` : le `\` annule l'expression regex attribuer de base et considère le point comme un caractère normale
	- `a.b` : Tout les **caractères** qui commence par `a` et se termine par `b` avec n'importe quoi entre les 2
	- `\{X.{3}Y\}` : Tout les mot qui commence par `{X` et se termine par `Y}` et avec exactement 3 carctère entre les deux
	- `[a-z]+|[A-Z]+` : Tout les caractère qui sont compris entre `a` et `z` au moins une fois **OU** tout les caracètre compris entre `A` et `Z` au moins une fois
	- `[^a-z]{2,4}` :  Tout les caractère qui **ne sont pas compris** entre `a` et `z` et de taille entre 2 et 4 caractère
	- `a(((b?c)+)|d*)` : Tout les motsqui commence par `a` puis le éventuellement le caractère `b` (ou pas du coup) suivi de c qu'on répète au moins une fois et autant de fois qu'on veut, **OU** le caractère `d` 0 ou plus de fois.
	- `([[:alunm:]]{2,})|([[:punct:]]{2})` : Un mot avec soit des lettres et des chiffres 2 fois ou plus **OU** une des caractère de pontuation 2 fois ou plus
	  
2) Building regular expressions
	- Strings of three letters followed by 2 to 6 digits : `[a-zA-Z]{3}[0-9]{2,6}` ou `[:alpha:]{3}[:digit:]{2,6}`
	- Sequences of non-empty words sepearated by at least one blank space : `[a-zA-Z]+([ ]+[a-zA-Z])*`
	- Arithmetic expressions (without parentheses) over hexadecimal numeric : `[[:xdigits:]]+([\x,\*,/,\-])+[[:xdigits:]]+)*`
	- Sentence containing one or more words. Words contains only letters and separated by spaces. A sentece starts with an Uppercase letter and end with a point : `[[:upper:]][[:lower:]]+([ ])+[[:lower:]]+)*\.`
3) Searching with regular expressions
	- ll the lines which contain verbs (use grep) : `cat Lab-6/English-train.cupt | grep VERB`
	- Only the forms of these verbs (column 2). Use the previous command, a pipe and cut : `cat Lab-6/English-train.cupt | grep VERB | cut --fields=2`
	- he forms of these verbs sorted alphabetically (sort) : `cat Lab-6/English-train.cupt | grep VERB | cut --fields=2 | sort`
	- The number of these forms (wc) : `cat Lab-6/English-train.cupt | grep VERB | cut --fields=2 | sort | wc --words`
	- The forms of these verbs with no repetitions (sort -u). Redirect this list to the unique-forms.txt file. `cat Lab-6/English-train.cupt | grep VERB | cut --fields=2 | sort -u > unique-forms.txt`
	- The number of these unique forms (wc) : `cat Lab-6/English-train.cupt | grep VERB | cut --fields=2 | sort -u | wc --words`
	- The list of unique lemmas (column 3) of these verbs. Redirect this list to the unique-lemmas.txt file. : `cat Lab-6/English-train.cupt | grep VERB | cut --fields=3 | sort -u > unique-lemmas.txt`
	- The differences between unique-forms.txt and unique-lemmas.txt (diff) `diff unique-lemmas.txt unique-forms.txt`
	- The forms which are no lemmas. For example, have is a form and a lemma at the same time, while told is a form but not a lemma (use cut -d to specify the delimiter of fields other than a tabulation). : `diff unique-forms.txt unique-lemmas.txt | grep "^<" | cut -c 3-`
