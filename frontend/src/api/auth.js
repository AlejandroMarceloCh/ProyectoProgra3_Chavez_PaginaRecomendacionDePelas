import axios from 'axios';

const API_URL = 'http://localhost:5050';

// Instancia de Axios para solicitudes de autenticación
const apiClient = axios.create({
  baseURL: API_URL,
  headers: {
    'Content-Type': 'application/json',
  },
  withCredentials: true, // Asegura que las cookies se envíen y gestionen automáticamente
});

// Función para iniciar sesión
export const login = async (username, password) => {
  if (!username || !password) {
    throw new Error('El usuario y la contraseña son obligatorios');
  }

  try {
    const response = await apiClient.post('/login', { username, password });
    return response.data;
  } catch (error) {
    console.error('Error al iniciar sesión:', error.response?.data || error.message);
    throw new Error(error.response?.data?.error || 'Error al iniciar sesión');
  }
};

// Función para registrarse
export const register = async (username, password) => {
  if (!username || !password) {
    throw new Error('El usuario y la contraseña son obligatorios');
  }

  try {
    const response = await apiClient.post('/register', { username, password });
    return response.data;
  } catch (error) {
    console.error('Error al registrar usuario:', error.response?.data || error.message);
    throw new Error(error.response?.data?.error || 'Error al registrar usuario');
  }
};
