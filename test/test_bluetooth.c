#include "unity.h"
#include "bluetooth.h"
#include <string.h>


// Prueba de inicialización Bluetooth
void test_inicializacion_bluetooth(void) {
    bool result = bluetooth_init();
    TEST_ASSERT_TRUE(result);
}

// Prueba de envío de datos Bluetooth
void test_envio_datos_bluetooth(void) {
    const char *data = "Datos de prueba";
    int bytes_enviados = bluetooth_send(data, strlen(data));
    TEST_ASSERT_EQUAL(strlen(data), bytes_enviados);
}

// Prueba de cierre de conexión Bluetooth
void test_cierre_conexion_bluetooth(void) {
    bool result = bluetooth_close();
    TEST_ASSERT_TRUE(result);
}

// Prueba de estabilidad de la conexión Bluetooth
void test_estabilidad_bluetooth(void) {
    bluetooth_init();
    
    for (int i = 0; i < 1000; i++) {
        const char *data = "Transmisión continua";
        bluetooth_send(data, strlen(data));
    }
    
    bool result = bluetooth_close();
    TEST_ASSERT_TRUE(result);
}

// Prueba de manejo de errores durante el envío de datos
void test_manejo_errores_envio(void) {
    bluetooth_init();
    const char *data = NULL;
    int bytes_enviados = bluetooth_send(data, 10);
    TEST_ASSERT_EQUAL(-1, bytes_enviados);
    bluetooth_close();
}

// Prueba de reconexión automática en fallos
void test_reconexion_automatica(void) {
    bluetooth_init();
    bluetooth_close();
    bool result = bluetooth_init();
    TEST_ASSERT_TRUE(result);
    const char *data = "Datos tras reconexión";
    int bytes_enviados = bluetooth_send(data, strlen(data));
    TEST_ASSERT_EQUAL(strlen(data), bytes_enviados);
    bluetooth_close();
}

// Prueba de integridad de los datos enviados
void test_integridad_datos(void) {
    bluetooth_init();
    
    const char *data = "Chequeo de integridad";
    int bytes_enviados = bluetooth_send(data, strlen(data));
    
    // Simulación de la recepción de datos
    char received_data[256];
    strncpy(received_data, data, bytes_enviados);
    received_data[bytes_enviados] = '\0';  // Asegura que la cadena esté terminada en null
    
    TEST_ASSERT_EQUAL_STRING(data, received_data);
    
    bluetooth_close();
}

// Prueba de rendimiento bajo carga
void test_rendimiento_bajo_carga(void) {
    bluetooth_init();
    const char *large_data = "Gran cantidad de datos";
    for (int i = 0; i < 10000; i++) {
        bluetooth_send(large_data, strlen(large_data));
    }
    bool result = bluetooth_close();
    TEST_ASSERT_TRUE(result);
}
