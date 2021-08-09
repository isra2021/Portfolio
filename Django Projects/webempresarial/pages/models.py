from django.db import models
from django.db.models.fields import CharField, SlugField

# Create your models here.
class Page(models.Model):
    name = models.CharField(max_length=100, verbose_name='Nombre de pagina')
    key = models.SlugField(max_length=100, unique=True, verbose_name='Nombre clave')
    content = models.TextField(verbose_name='Contenido')
    created = models.DateTimeField(auto_now_add=True, verbose_name='Fecha de creacion')
    updated = models.DateTimeField(auto_now=True, verbose_name='Fecha de actualizacion')

    class Meta:
        verbose_name = 'Pagina'
        verbose_name_plural = 'Paginas'
        ordering = ['-created']
    
    def __str__(self):
        return self.name
