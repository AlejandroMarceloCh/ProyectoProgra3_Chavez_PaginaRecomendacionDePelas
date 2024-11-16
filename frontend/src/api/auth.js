// src/api/auth.js
import axios from 'axios';

const API_URL = 'http://localhost:5050';

// Instancia centralizada de axios con configuración básica
const apiClient = axios.create({
  baseURL: API_URL,
  headers: {
    'Content-Type': 'application/json',
  },
});

// Interceptor para manejo global de errores (opcional)
apiClient.interceptors.response.use(
  response => response,
  error => {
    console.error("Error en la API:", error.response ? error.response.data : error.message);
    return Promise.reject(error);
  }
);

// Función para iniciar sesión
export const login = async (username, password) => {
  try {
    const response = await apiClient.post('/login', { username, password });
    return response.data;
  } catch (error) {
    console.error("Error al iniciar sesión:", error.response ? error.response.data : error.message);
    throw new Error(error.response?.data?.message || "Error al iniciar sesión");
  }
};

// Función para registrarse
export const register = async (username, password) => {
  try {
    const response = await apiClient.post('/register', { username, password });
    return response.data;
  } catch (error) {
    console.error("Error al registrar usuario:", error.response ? error.response.data : error.message);
    throw new Error(error.response?.data?.message || "Error al registrar usuario");
  }
};
