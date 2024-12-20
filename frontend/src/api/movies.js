import axios from 'axios';

const API_BASE_URL = 'http://localhost:5050';

// Instancia de Axios para manejar solicitudes con cookies
const apiClient = axios.create({
  baseURL: API_BASE_URL,
  headers: {
    'Content-Type': 'application/json',
  },
  withCredentials: true, // Asegura que las cookies se envíen y gestionen automáticamente
});

// Obtener el username almacenado localmente
const getUsername = () => {
  const username = localStorage.getItem('username');
  if (!username) {
    throw new Error('Usuario no autenticado. Por favor, inicia sesión.');
  }
  return username;
};

// Buscar películas por query
export const searchMovies = async (query) => {
  if (!query) {
    throw new Error('La búsqueda no puede estar vacía');
  }

  try {
    const username = getUsername();
    const response = await apiClient.post(
      '/search',
      { query, username }, // Ahora enviamos `username` directamente en el cuerpo
    );
    return response.data;
  } catch (error) {
    console.error('Error al buscar películas:', error.response?.data || error.message);
    throw error;
  }
};

// Obtener recomendaciones
export const getRecommendations = async () => {
  try {
    const username = getUsername();
    const response = await apiClient.get('/recommendations', {
      headers: {
        Username: username,
      },
    });
    return response.data;
  } catch (error) {
    console.error('Error al obtener recomendaciones:', error.response?.data || error.message);
    throw error;
  }
};

// Obtener lista de películas para "ver más tarde"
export const getWatchLater = async () => {
  try {
    const username = getUsername();
    const response = await apiClient.get('/watchlater', {
      headers: {
        Username: username,
      },
    });
    return response.data;
  } catch (error) {
    console.error("Error al obtener lista de 'Ver más tarde':", error.response?.data || error.message);
    throw error;
  }
};

// Marcar película como "Me gusta"
export const likeMovie = async (movieId) => {
  try {
    const username = getUsername();
    const response = await apiClient.post(
      '/likeMovie',
      { movieId },
      {
        headers: {
          Username: username,
        },
      }
    );
    return response.data;
  } catch (error) {
    console.error('Error al marcar como "Me gusta":', error.response?.data || error.message);
    throw error;
  }
};

// Agregar película a "Ver más tarde"
export const watchLaterMovie = async (movieId) => {
  try {
    const username = getUsername();
    const response = await apiClient.post(
      '/watchLaterMovie',
      { movieId },
      {
        headers: {
          Username: username,
        },
      }
    );
    return response.data;
  } catch (error) {
    console.error('Error al agregar a "Ver más tarde":', error.response?.data || error.message);
    throw error;
  }
};
