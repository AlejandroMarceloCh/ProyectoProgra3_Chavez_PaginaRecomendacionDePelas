// src/components/MovieItem.js
import React, { useState } from 'react';
import '../styles/MovieItem.css';

const MovieItem = ({ movie, onLike, onWatchLater }) => {
    const [showOptions, setShowOptions] = useState(false);
    const [liked, setLiked] = useState(false);
    const [watchLater, setWatchLater] = useState(false);

    const handleCardClick = () => {
        setShowOptions(!showOptions); // Alterna entre mostrar y ocultar los botones
    };

    const handleLike = (e) => {
        e.stopPropagation(); // Evita que el clic cierre el menú
        setLiked(!liked);
        onLike(movie.id);
    };

    const handleWatchLater = (e) => {
        e.stopPropagation();
        setWatchLater(!watchLater);
        onWatchLater(movie.id);
    };

    return (
        <div className={`movie-item ${showOptions ? 'show-options' : ''}`} onClick={handleCardClick}>
            <h3>{movie.title}</h3>
            <p>{movie.plot}</p>
            
            {/* Opciones de botones, solo visibles cuando `showOptions` es true */}
            {showOptions && (
                <div className="movie-item-options">
                    <button 
                        className={`like-button ${liked ? 'active' : ''}`}
                        onClick={handleLike}
                    >
                        Me gusta
                    </button>
                    <button 
                        className={`watch-later-button ${watchLater ? 'active' : ''}`}
                        onClick={handleWatchLater}
                    >
                        Ver más tarde
                    </button>
                </div>
            )}
        </div>
    );
};

export default MovieItem;
