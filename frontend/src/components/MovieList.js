// src/components/MovieList.js
import React from 'react';
import MovieItem from './MovieItem';
import { likeMovie, watchLaterMovie } from '../api/movies';
import '../styles/MovieList.css';

const MovieList = ({ movies }) => {
    const handleLike = async (movieId) => {
        await likeMovie(movieId); // Llama la API para marcar como "Me gusta"
    };

    const handleWatchLater = async (movieId) => {
        await watchLaterMovie(movieId); // Llama la API para "Ver más tarde"
    };

    return (
        <div className="movie-list">
            {movies.map((movie) => (
                <MovieItem
                    key={movie.id}
                    movie={movie}
                    onLike={handleLike}
                    onWatchLater={handleWatchLater}
                />
            ))}
        </div>
    );
};

export default MovieList;
