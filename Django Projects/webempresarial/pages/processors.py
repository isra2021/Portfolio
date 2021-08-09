from .models import Page

def context_dict(request):
    ctx = {}
    pages = Page.objects.all()
    for page in pages:
        ctx[page.key] = page 
    return ctx

    