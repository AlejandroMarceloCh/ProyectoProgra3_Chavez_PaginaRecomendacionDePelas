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

// Buscar películas por query
export const searchMovies = async (query) => {
  try {
    const response = await apiClient.post('/search', { query });
    return response.data;
  } catch (error) {
    console.error('Error al buscar películas:', error.response?.data || error.message);
    throw error;
  }
};

// Obtener recomendaciones
export const getRecommendations = async () => {
  try {
    const response = await apiClient.get('/recommendations');
    return response.data;
  } catch (error) {
    console.error('Error al obtener recomendaciones:', error.response?.data || error.message);
    throw error;
  }
};

// Marcar película como "me gusta"
export const likeMovie = async (movieId) => {
  try {
    await apiClient.post('/like', { movieId });
  } catch (error) {
    console.error("Error al marcar película como 'Me gusta':", error.response?.data || error.message);
    throw error;
  }
};

// Agregar película a "ver más tarde"
export const watchLaterMovie = async (movieId) => {
  try {
    await apiClient.post('/watchlater', { movieId });
  } catch (error) {
    console.error("Error al agregar película a 'Ver más tarde':", error.response?.data || error.message);
    throw error;
  }
};

// Obtener lista de películas para "ver más tarde"
export const getWatchLater = async () => {
  try {
    const response = await apiClient.get('/watchlater');
    return response.data;
  } catch (error) {
    console.error("Error al obtener lista de 'Ver más tarde':", error.response?.data || error.message);
    throw error;
  }
};
