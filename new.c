/*
** EPITECH PROJECT, 2024
** RUSH 02
** File description:
** C
*/

#include "object.h"
#include "new.h"

Object *new(const Class *class, ...)
{
    va_list args;
    va_start(args, class);
    Object *stock = va_new(class, &args);
    va_end(args);
    return (stock);
}

Object *va_new(const Class *class, va_list *ap)
{
    Object *new_object = malloc(class->__size__);
    memcpy(new_object, class, class->__size__);
    if (class->__ctor__ != NULL) {
        class->__ctor__(new_object, ap);
        return(new_object);
    } else {
        raise("Erreur ctor NULL");
    }
}

void delete(Object *ptr)
{
    Class *class = ptr;
    if (ptr == NULL) {
        raise("Out of Memory");
    }
    class->__dtor__(ptr);
    free(ptr);
}
