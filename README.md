VENTANA DE INICIO	

Seleccionar si desea ingresar como administrador o usuario o si desea salir
				-como admin. usuario "sudo" contraseña "AbCd"
				-como usuario "1007689195" contraseña "1205" (o se puede registrar en la ventana de admin)

MENU DE ADMIN

->Imprime el inventario

Agregar algo al inventario ->Ingresas la id
			   ->El nombre del producto
			   ->La cantidad de este
			   ->y su precio por unidad
			   (Tambien puedes editar algo de una ya registrado siguiendo estos mismos pasos)

Crear combo	->sera un ciclo que te ira pidiendo constantemente por el id del producto que deseas agregar
		->luego te pedira la cantidad de cada producto
		->y luego el precio de este combo

Crear el reporte de las ventas	->simplemente guardara en un archivo las ventas realizadas mientras el programa esta abierto, si se cierra sin guardarlas se perderan

Registrar usuarios	->les pedira la cc y la contraseña luego los guarda en un archivo

Salir del menu

MENU DE USUARIO

->Imprime el menu de combos

Comprar combo	->le pide al usuario que ingrese el numero del combo
		->le pide el dinero y revisa si hay existencias, si no hay existencias le devuelve el dinero
		->si hay existencias le pide al usuario que ingrese la sala y el puesto para llevarle el pedido, y luego se guara enun registro temporal

Salir

*desido usar mapas por que me es mas facil iterar entre ellos y tambien porque me parecio que los combos e inventario al tener un numero o un id seria mas facil de guardar asi y tambien usar su valor*