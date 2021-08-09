from django.db import models
from django.db.models.fields import CharField

# Create your models here.
class Link(models.Model):
    key = models.SlugField(max_length=100, unique=True, verbose_name='Nombre clave')
    name = models.CharField(max_length=100, verbose_name='Red social')
    url = models.URLField(max_length=200, null=True, blank=True, verbose_name='Enlace')
    created = models.DateTimeField(auto_now_add=True, verbose_name='Fecha de creacion')
    updated = models.DateTimeField(auto_now=True, verbose_name='Fecha de actualizacion')

    class Meta:
        verbose_name = 'Enlace'
        verbose_name_plural = 'Enlaces'
        ordering = ['-created']
    
    def __str__(self):
        return self.name

