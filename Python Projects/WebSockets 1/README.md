# Punto Estrella
 
Las tecnologías que permiten el uso de dominios con nombres en cualquier tipo de lenguaje o incluso íconos son:
 
- Unicode
- Internacionalización de Nombres de Dominio en Aplicaciones (IDNA)
 
## Unicode
 
Esta norma se introduce en 1991, es una gran tabla, que en la actualidad asigna un código a cada uno de los más de cincuenta mil símbolos, los cuales abarcan todos los alfabetos europeos, ideogramas chinos, japoneses, coreanos, muchas otras formas de escritura, y más de un millar de símbolos locales.
 
Además Unicode es un metodos de codificacion de caracteres pero existen otros métodos que permiten convertir un caracter o símbolo a otro sistema de representación, como: Normas de Transmisión, tablas tipográficas y ASCII Extendido entre otros
 
## IDNA
 
Es un mecanismo definido en el año 2003 para manejar nombres de dominio IDN que contienen caracteres no ASCII.
Como no podían ser manejados por la infraestructura DNS existente fue diseñado para una máxima compatibilidad hacia atrás en lugar de rediseñar todo por comlet. Se decidió que los nombres de dominio con caracteres no-ASCII deben ser convertidos a una forma basada en ASCII por los navegadores web y otras aplicaciones de usuario; IDNA especifica cómo debe realizarse esta conversión.
 
Una aplicación habilitada para IDNA es capaz de convertir entre ASCII restringido y representaciones no ASCII para un dominio, utilizando la forma ASCII en los casos donde se necesite (como el lookup DNS), pero que sea capaz de presentar la forma no ASCII de mejor lectura a los usuarios. Las aplicaciones que no soporten IDNA no serán capaces de manejar nombres de dominio con caracteres no ASCII, pero todavía serán capaces de acceder a tales dominios si les es dado el equivalente ASCII (normalmente más críptico).
 
## Curiosidades
 
También encontramos algo llamado "UTF-8" que muchas veces en los heads de archivos html sabemos encontrarlo (para ser más precisos ```<meta charset="UTF-8">```) y mientras investigabamos del tema, entendimos que es un formato de codificación de caracteres unicode e ISO 10646 (estándar internacional que define el conjunto de caracteres universal), vimos que posee algunas características interesantes, como que puede representar cualquier carácter unicode, pero que gracias a sus características lo hacen atractivo en la codificación de correos electrónicos y páginas web.
 
Además encontramos Punycode que es una sintaxis de codificación que usa una cadena Unicode que puede ser traducida en una cadena de caracteres compatibles con nombres de red y que es usada como parte de IDNA, es muy práctico para gestionar dominios con caracteres IDN en empresas de hosting que no lo permiten, ya que si soportan la notación punycode, pero para poder usarlo correctamente hay que asegurarse que el navegador permite usar la codificación UTF-8.