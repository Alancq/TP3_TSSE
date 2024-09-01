#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include <stddef.h>
#include <stdbool.h>

/**
 * @brief Inicializa el módulo Bluetooth.
 * 
 * Esta función configura e inicializa el módulo Bluetooth para que
 * esté listo para la transmisión de datos.
 * 
 * @return true si la inicialización fue exitosa.
 * @return false si ocurrió un error durante la inicialización.
 */
bool bluetooth_init(void);

/**
 * @brief Envía datos a través de Bluetooth.
 * 
 * Esta función envía un bloque de datos a través de la conexión Bluetooth
 * previamente inicializada. Se debe asegurar que la conexión esté activa
 * antes de llamar a esta función.
 * 
 * @param data Puntero a los datos a enviar.
 * @param length Longitud de los datos en bytes.
 * @return int Número de bytes enviados. Devuelve -1 si ocurre un error.
 */
int bluetooth_send(const char *data, size_t length);

/**
 * @brief Cierra la conexión Bluetooth.
 * 
 * Esta función cierra la conexión Bluetooth de manera segura, liberando
 * cualquier recurso utilizado por el módulo.
 * 
 * @return true si la conexión se cerró correctamente.
 * @return false si ocurrió un error durante el cierre.
 */
bool bluetooth_close(void);

#endif // BLUETOOTH_H
